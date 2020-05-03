# ucsToSsc
An utility to convert Pump It Up's .ucs file to .ssc file for plays in StepF2/StepMania/StepPrime. 

You can edit and compile these source codes; however, you cannot re-distribute the source codes / compiled codes as a public project. 

Language: C++11

How to use the CLI example (ucsToSsc.exe):
```
ucsToSsc ["input\path.ucs"] ["output\path.ssc"] ["title"] ["artist"] ["music-file"] [level]
ucsToSsc ["input\path.ucs"] ["output\path.ssc"] ["title"] ["artist"] ["music-file"] [level] [specifiedBPM]
ucsToSsc ["input\path.ucs"] ["output\path.ssc"] ["title"] ["artist"] ["music-file"] [level] [specifiedBPM] [offset-MS]
```
```
ucsToSsc ["input\path.ucs"] ["output\path.ssc"]
```
- This input will generate default values for the other parameters, which is NOT recommended.

For example:
```
ucsToSsc "C:\Bi s23.ucs" "C:\Bi.ssc" "Bi SDVX" "Sound Voltex" "bi.mp3" 23 169 -200
```

Warning: The path inputs should be in the format:
```
"path\to\your\file.ucs"
```

Changelog:
- 3 May 2020: Add source codes and CLI example
