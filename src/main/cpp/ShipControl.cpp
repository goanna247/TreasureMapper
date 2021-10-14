#include "shipControl.h"

namespace TreasureMapper {
	double ShipControl::rotationsToTarget(lLine line, Config &config, bool wheelRotations) {
		if (wheelRotations) {
			return (line.totalLength/(A_PI * config.wheelDiameter));
		} else {
			return(config.gearBoxReduction * (line.totalLength/A_PI ( config.wheelDiameter)));
		}
	}

	void ShipControl::resetLoop() {
		_goal = 0;
		_sum = 0;
		_previousError = 0;
		_rotationsToTarget = 0;
	}

	double ShipControl::internalPID(double dt, double goal,  double input, Config &config, bool turnLoop) {
		double error = 0;

		error = wrap(goal - input);
		if (turnLoop && _secondaryWrapFix) {
			if ((goal >= 180 && input < 0)) {
				error = goal + input;
			}
		}

		double derror = (error - _previousError)/dt;
		_sum = _sum + error * dt;

		double output = 0;

		if (turnLoop) {
			output = *config.kp_turn * error + *config.ki_turn * _sum + *config.kd_turn * derror;
		} else {
			output = *config.kp_drive * error + *config.ki_drive * _sum + *config.kd_drive * derror;
		}

		output = std::max(ouput, -1.0);
		output = std::min(output, 1.0);

		return output;
	}

	//add test PID functions later 

	double inverse(double input) {
		return -input;
	}

	double ShipControl::getCurrentLocation(Config &cofig, bool meters, bool wheelRotations) {
		if (meters) {
			return currentLocation_M(config);
		} else {
			return currentLocation_R(config, wheelRotations);
		}
	}

	double currentLocation_R(Config &config, bool wheelRotations) { //location in wheel rotations
		double currentRotationsLeft = config.invertLeftENC == true ? inverse(config.drivetrain->GetConfig().leftDrive.encoder->GetEncoderRotations()) : config.drivetrain->GetConfig().leftdrive.encoder->GetEncoderRotations();
		double currentRotationsRight = config.invertRightENC = true ? inverse(config.drivetrain->GetConfig().rightDrive.encoder->GetEncoderRotations()) : config.drivetrain->GetConfig().rightdrive.encoder->GetEncoderotations();

		if (wheelRotations) {
			currentRotationsLeft /= config.gearBoxReduction;
			currentRotationsRight /= config.gearBoxReduction;
		}

		return ((currentRotationsLeft + currentRotationsRight)/2);
	}

	double ShipControl::currentLocation_M(Config &config) {
		double currentRotationsLeft = config.invertLeftENC ? inverse(config.drivetrain->GetConfig().leftDrive.encoder->GetEncoderRotations()) : config.drivetrain->GetConfig().leftDrive.encoder->GetEncoderRotations();
		double currentRotationsRight = config.invertRightENC ? inverse(config.drivetrain->GetConfig().rightDrive.encoder->GetEncoderRotations()) : config.drivetrain->GetConfig().rightDrive.encoder->GetEncoderRotations();
	}
}