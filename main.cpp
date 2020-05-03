#include "ucsToSsc.h"
;

int main(int argc, char *argv[]) {
	//An example of executable from CLI.
	/*
		Arguments:
			1: Input path
			2: Output path
			3: Title
			4: Artist
			5: File name (for example, CS223.mp3 only)
			6: Level
			7: Specified BPM (optional, for AV compatibility)
			8: Offset (ms) (optional)
	*/
	if (argc<3) {
		cout << "Usage:" << endl;
		cout << "You can use one of these inputs:" << endl;
		cout << "----------------------------------------------------------------------" << endl;
		cout << "ucsToSsc [\"input\\path.ucs\"] [\"output\\path.ssc\"]" << endl;
		cout << "ucsToSsc [\"input\\path.ucs\"] [\"output\\path.ssc\"] [\"title\"] [\"artist\"] [\"music-file\"] [level]" << endl;
		cout << "ucsToSsc [\"input\\path.ucs\"] [\"output\\path.ssc\"] [\"title\"] [\"artist\"] [\"music-file\"] [level] [specifiedBPM]" << endl;
		cout << "ucsToSsc [\"input\\path.ucs\"] [\"output\\path.ssc\"] [\"title\"] [\"artist\"] [\"music-file\"] [level] [specifiedBPM] [offset-MS]" << endl;
		cout << endl;
		cout << "Note: [specifiedBPM] is helpful if you use AV (Auto Velocity)." << endl;
		return -1;
	}
	if (argc==3) {
		if (ucsToSsc(argv[1], argv[2],"DefaultTitle","DefaultArtist","file.mp3",1, -1, -1)) {
			cout << "Successful";
			return 0;
		};
	}
	if (argc==7) {
		if (ucsToSsc(argv[1], argv[2],argv[3],argv[4],argv[5],stoi(argv[6]), -1, -1)) {
			cout << "Successful";
			return 1;
		};
	}
	if (argc == 8) {
		if (ucsToSsc(argv[1], argv[2], argv[3], argv[4], argv[5], stoi(argv[6]), stod(argv[7]), -1)) {
			cout << "Successful";
			return 1;
		};
	}
	else {
		if (ucsToSsc(argv[1], argv[2], argv[3], argv[4], argv[5], stoi(argv[6]), stod(argv[7]), stoi(argv[8]))) {
			cout << "Successful";
			return 1;
		};
	}
	return 9;
};