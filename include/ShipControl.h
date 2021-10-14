#include "Drivetrain.h"
#include "path.h"
#include "NTProvider.h"
#include "utilities/genericHeaders.h"

namespace TreasureMapper {
	class ShipControl : public Path {
	 public:
		struct Config {

			wml::Drivetrain *drivetrain;
			bool invertLeftENC = false;
			bool invertRightENC = false;

			double *dp_drive,
			*ki_drive,
			*kd_drive,

			*kp_turn,
			*ki_turn,
			*kd_turn,

			gearBoxReduction = 0,
			wheelDiameter = 0, //measured in Meters
			maxSpeed = 0, //maybe i should limit this
			maxTurnSpeed = 0; 

			bool dynamicLimits = false;
		};

		rotationsToTarget(lLine line, Config &config, bool wheelRotations);

		resetLoop();

		internalPID(double dt, double goal, double input, Config &config, bool turnLoop);

		inverse(double input);

		getCurrentLocation(Config &config, bool meters, bool wheelRotations);

		currentLocation_M(Config &config);

		currentLocation_R(Config &config, bool wheelRotations);
	};
}

//so whos julia? -> sister apparently 