#include "ucsToSsc.h"

bool ucsToSsc(std::string path, std::string outpath, std::string title, std::string artist, std::string musicfile, int level, double specBPM, int msOffset) {
	vector<std::string> cmd;
	ofstream 			output(outpath);

	if (!output.is_open())
		return false;

	/* INIT */

	output << "#VERSION:0.81;" 								<< endl;
	output << "#TITLE:" << title << ";" 					<< endl;	
	output << "#SUBTITLE:;" 								<< endl;
	output << "#ARTIST:" << artist << ";" 					<< endl;	
	output << "#TITLETRANSLIT:;" 							<< endl;
	output << "#SUBTITLETRANSLIT:;" 						<< endl;
	output << "#ARTISTTRANSLIT:;" 							<< endl;
	output << "#GENRE:" << ";" 								<< endl;
	output << "#ORIGIN:;" 									<< endl;
	output << "#CREDIT:;" 									<< endl;
	output << "#BANNER:" << ";"								<< endl;
	output << "#BACKGROUND:" << ";"							<< endl;
	output << "#PREVIEWVID:;" 								<< endl;
	output << "#CDTITLE:;" 									<< endl;
	output << "#MUSIC:" << musicfile << ";"					<< endl;	
	
	// OFFSET
	output << "#OFFSET:" << ";"								<< endl;
	output << "#SAMPLESTART:0.000000;" 						<< endl;
	output << "#SAMPLELENGTH:10.000000;" 					<< endl;
	output << "#SELECTABLE:YES;" 							<< endl;
	output << "#BPMS:" << bpmSection(path) << ";" 			<< endl;
	output << "#TIMESIGNATURES:0.000=4=4;" 					<< endl;
	output << "#TICKCOUNTS:0.000=4;"  						<< endl;
	output << "#COMBOS:0.000=1;" 							<< endl;
	output << "#SPEEDS:0.000=1.000=0.000=0;" 				<< endl;
	output << "#SCROLLS:0.000=1.000;" 						<< endl;
	output << "#LABELS:0.000=Song Start;" << endl;
	if (specBPM > 0) {
		output << "#DISPLAYBPM:" << specBPM << ";"			<< endl;
	}
	output << endl << endl;

	output << "//----------converted from UCS-----------"	<< endl;
	output << "#NOTEDATA:;" 								<< endl;
	output << "#STEPSTYPE:" << stepMode(path) << ";"		<< endl;
	output << "#DESCRIPTION:UCS Converted;"					<< endl;
	output << "#DIFFICULTY:Edit;" 							<< endl;
	output << "#METER:" << level << ";" 					<< endl;	
	output << "#RADARVALUES:;" 								<< endl;
	if (msOffset > 0) {
		output << "#OFFSET:" << (double)msOffset/1000 << ";"<< endl;
	}
	else {
		output << "#OFFSET:" << ";"							<< endl;
	}
	output << "#BPMS:" << bpmSection(path) << ";" 			<< endl;
	output << "#STOPS:;" 									<< endl;
	output << "#DELAYS:;" 									<< endl;
	output << "#WARPS:;" 									<< endl;
	output << "#TIMESIGNATURES:0.000=4=4;" 					<< endl;
	output << "#TICKCOUNTS:0.000=4;" 						<< endl;
	output << "#COMBOS:0.000=1;" 							<< endl;
	output << "#SPEEDS:0.000=1.000=0.000=0;" 				<< endl;
	output << "#SCROLLS:" << scrollSection(path) << ";" 	<< endl;
	output << "#FAKES:;" 									<< endl;
	output << "#LABELS:0.000=Song Start;" 					<< endl;
	if (specBPM > 0) {
		output << "#DISPLAYBPM:" << specBPM << ";"			<< endl;
	}
	output << "#NOTES:" << endl << stepSection(path) << ";" << endl;

	output.close();
	if (output.is_open())
		return false;
	return true;
}
