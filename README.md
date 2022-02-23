# BarrenLandAnalysis
Target Case Study 

Requirements:
•	Complete the exercise in the technical stack of your choice.
o	When appropriate use a data store of your choice.
o	Use any external frameworks you desire
o	Be ready to discuss your recommendations to make your solution suitable for use in a production environment 

•	Provide evidence of the result to the interviewers (choose one)
o	Unit test results or other documented output
o	Hosted instance of the implementation
o	Runnable instance of the implementation on your computer

•	The end result should be a functional implementation of the problem with associated tests
o	Provide the working code either in a publicly accessible hosted repository or a zip file containing all necessary build steps and dependencies
o	Rename .js files to .js.txt if emailing code
o	Provide a README.md file with instructions for testing, running and interacting with your application and any details you feel are relevant to share

Problem:
•   You have a farm of 400m by 600m where coordinates of the field are from (0, 0) to (399, 599). A portion of the farm is barren, and all the barren land is in the form of rectangles. Due to these rectangles of barren land, the remaining area of fertile land is in no particular shape. An area of fertile land is defined as the largest area of land that is not covered by any of the rectangles of barren land. 
Read input from STDIN. Print output to STDOUT 

•   Input 
You are given a set of rectangles that contain the barren land. These rectangles are defined in a string, which consists of four integers separated by single spaces, with no additional spaces in the string. The first two integers are the coordinates of the bottom left corner in the given rectangle, and the last two integers are the coordinates of the top right corner. 

•   Output 
Output all the fertile land area in square meters, sorted from smallest area to greatest, separated by a space. 
Sample: 
{“0 292 399 307”} => 116800  116800
{“48 192 351 207”, “48 392 351 407”, “120 52 135 547”, “260 52 275 547”}  => 22816 192608

How to build:
1. Open cloned folder in command prompt.
2. Run make to build executables
3. Run BarrenLandAnalysis.exe with desired input parameters

How to use:
• BarrenLandAnalysis.exe
    -w : custom width setter; must have valid number after
    -h : custom height setter; must have valid number after
    -runtest : perform all test cases defined in Tests/test_main.cpp; will ignore any other parameters