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
	*/
	if (argc<3) {
		cout << "Path name is required";
		return -1;
	}
	if (argc==3) {
		if (ucsToSsc(argv[1], argv[2],"DefaultTitle","DefaultArtist","file.mp3",1)) {
			cout << "Successful";
			return 0;
		};
	}
	else {
		if (ucsToSsc(argv[1], argv[2],argv[3],argv[4],argv[5],stoi(argv[6]))) {
			cout << "Successful";
			return 1;
		};
	}

	return 9;
};