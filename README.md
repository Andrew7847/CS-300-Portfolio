# CS-300-Portfolio
Examples of work from both main projects from CS300: Data Structures and Algorithms at SNHU. Below are the answers to questions regarding the projects.

# What was the problem you were solving in the projects for this course?
- ABC University requested a program that would be able to take a CSV of course information (Course ID, Description, and Prerequisites) as input. Then the information was to be stored in an appropriate data structure (in this case a vector was used), sorted alphanumerically, and be able to displayed either by searching a specific course or by printing the whole list. 

# How did you approach the problem? Consider why data structures are important to understand.
- The most important thing to consider with this project was how the data was going to be manipulated and stored. We were given a choice of a vector, a hash map, and a binary search tree as options. In this instance I chose a vector due to the runtime analysis that was done on the pseudocode and also space considerations. Originally, I believed a hash map was going to be the best choice but it wouldn't make much sense to use that as all of one type of course (all math courses for example) would end up in one bucket. With the limited data we were given, there would have only been two buckets so that would not have been logical. 

# How did you overcome any roadblocks you encountered while going through the activities or project?
- I primarily relied on the C++ documentation to solve any issues I encountered especially when looking for vector member functions that would make life easier and cleaner. I also heavily used the debugging tool on Visual Studio to figure out any issues I had specifically with loading the data from the CSV into the data structure. 

# How has your work on this project expanded your approach to designing software and developing programs?
- This project really improved my debugging skills and also increased my ability to read and understand the language documentation to find specifically what I needed to know. Also, this project helped me understand the significance of writing good pseudocode before jumping right into coding and really taking the time to consider each and every option at my disposal.

# How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?
- This project helped me to write better comments in my code specifically when it comes to the despriction of my individual methods with the parameters, the return type, and what the intent of the method is. This ultimately makes my code more readable and modular. I can easily grab a method from this project and use it elsewhere because I can see exactly what it does and what it expects as input. Also, by doing the runtime analysis on my pseudocode, it forced me to clean up any unnecessary lines that I had and make the code more concise overall.
