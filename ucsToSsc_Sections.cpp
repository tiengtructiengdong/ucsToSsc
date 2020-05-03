#include "ucsToSsc_Sections.h"

std::string bpmSection(std::string path) {
	ifstream 				step(path);
	vector<std::string>		cmd;
	std::string				line;

	int             currentSplit = 1;
	double          position = 0.000000;

	getline(step, line);
	getline(step, line);
	
	double			bpm;

	while (getline(step, line)) {

		// BPM
		if (line.at(4) == '=') {
			bpm = stod(line.substr(line.find("=") + 1));
		}

		// Split
		else if (line.at(4) == 'i') {
			currentSplit = stoi(line.substr(line.find("=") + 1));
			cmd.push_back(to_string(position) + '=' + to_string(bpm*(double)currentSplit/4));
		}

		// Note lines
		else if (line.at(4) != 'a' && line.at(4) != 't') {
			position += 0.25;
		}

	}

	step.close();
	if (step.is_open()) {
		cout << "Error";
	}
	return join(cmd, ",\n");
}


std::string stepSection(std::string path) {

	ifstream 			step(path);
	vector<std::string> cmd;
	std::string         line;

	/*
	Indicates if the line covers one segment in SSC.
	*/
	int					complete = 16;

	for (int i = 0; i < 6; i++)
		getline(step, line);

	int					lineSplit;

	while (getline(step, line)) {


		// Note line
		if (line.at(4) != 'i' && line.at(4) != '=' && line.at(4) != 'a' && line.at(4) != 't') {
			cmd.push_back(toSsc(line));
			complete -= 1;
		}

		// Segment omplete
		if (complete == 0) {
			complete = 16;
			cmd.push_back(",");
		}
	}


	step.close();
	if (step.is_open()) {
		cout << "Error";
	}
	cmd.pop_back();
	return join(cmd, "\n");
}


std::string scrollSection(std::string path) {
	ifstream 				step(path);
	vector<std::string>  	cmd;
	std::string          	line;

	int             currentSplit 	= 1;
	double          position 		= 0.000000;

	getline(step, line);
	getline(step, line);

	while (getline(step, line)) {

		// Split
		if (line.at(4) == 'i') {
			currentSplit = stoi(line.substr(line.find("=") + 1));
			cmd.push_back(to_string(position) + '=' + to_string(4/(double)currentSplit));
		}

		// Note lines
		else if (line.at(4) != '=' && line.at(4) != 'a' && line.at(4) != 't') {
			position += 0.25;
		}
	}

	step.close();
	if (step.is_open()) {
		cout << "Error";
	}
	return join(cmd, ",\n");
}


std::string stepMode(std::string path) {
	ifstream 		step(path);
	std::string     line;

	getline(step, line);
	getline(step, line);

	if (line.substr(line.find("=") + 1) == "Single" || line.substr(line.find("=") + 1) == "S-Performance") {
		step.close();
		return "pump-single";
	}

	step.close();
	return "pump-double";
}