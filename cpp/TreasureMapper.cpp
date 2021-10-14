#include "TreasureMapper.h"

namespace TreasureMapper {
	// TreasureMapper::treasureMapper(Config &config) : _config(config) { 
	// 	//print config stuff
	// }

	// Path::lPath TreasureMapper::buildPath(lPath path, double startAngle, double endAngle) {
	// 	double totalLength = 0;
	// 	for (size_t i = 0; i < path.lines.size(); i++) {
	// 		path.lines[i].length = getLineLength(path.lines[i]);
	// 		path.lines[i].angle = getLineAngle(path.lines[i]);

	// 		std::cout << "Line " << i << " length: " << path.lines[i].length << std::endl;
	// 		std::cout << "Angle " << i << " angle: " << path.lines[i].angle << std::endl;

	// 		totalLength += path.lines[i].length;
	// 		path.lines[i].totalLength = totalLength;
	// 	}

	// 	PathState newState;
	// 	newState.setState(PathState::State::kStartAngle);

	// 	path.pathStartAngle = startAngle;
	// 	path.pathEndAngle = endAngle;
	// 	path.pathState = newState;
	// 	path.pathLength = totalLength;

	// 	std::cout << "Total length: " << totalLength << std::endl;
	// 	return path;
	// }

	// void TreasureMapper::linearDrive(lPath *path, double dt, bool reverse) {
	// 	//linear sail? 
	// 	if (__disableAngleSE) {
	// 		if (driveToTarget(path, reverse, dt, _config)) {
				
	// 		}
	// 	}
	// }

	// bool TreasureMapper::followPath(lPath *path, double dt, bool reverse) {
	// 	return false;
	// }

	// bool TreasureMapper::atCross();
}

int main() {
	return 0;
}