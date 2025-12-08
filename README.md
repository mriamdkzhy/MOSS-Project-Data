# 🌱 MOSS Project Data
Detecting LLM generated code with MOSS. <br>
This github repo has some of the data and scripts used for testing the MOSS similarity checker for my project in 'Topics for Computer Science'.
## What is MOSS?
[MOSS](https://theory.stanford.edu/~aiken/moss/) is an automated similarity checker that is used by universities for coding assignments. <br>
## Project Aim
The aim of this project was to find solutions for improving MOSS as it cannot detect LLM-generated scripts. 
The project looked at what methods and what combination of methods could surpass MOSS for cheating manually as well as its ability to detect LLM-generated code.
## Method Investigated
To compare the performance of the models the main metrics used were: ‘Average Percentage’ and ‘Lines of Code’. 
MOSS outputs the similarity of percentage of the first file compared to the second file and vice versa. To be able to compare the similarities, the Average Percentage was created.  Average Percentage is the average of Percentage 1 and Percentage 2.
Lines of Code is a measure outputted by MOSS.
## Dataset
This repository stores the data that was used in this project.
### Generating Data
For the investigation on LLMs, a database of results was made. Three main variables were considered when creating the database: the model, model type (generic or code-specific) and the question difficulty.
Nine LLMs were chosen with four being code-specific LLMs. The five generic LLMs were ChatGPT 4o, Google Gemini 1.5 Flash, Llama 3.1, Claude 3.5 Sonnet and Mistral Large 2. The four code-specific models were BlackBox.ai, Mistral Codestral, Replit AI and Github copilot. 
For the input, three questions were chosen. These three questions were Leetcode questions of varying difficulty (Easy, Medium and Hard) as shown in the table.<br>
|Difficulty	|Question|
| ------------- | ------------- |
|Easy	|Contains Duplicate. Given an integer array nums, return true if any value appears more than once in the array, otherwise return false.|
|Medium	|Remove Node From End of Linked List, You are given the beginning of a linked list head, and an integer n. Remove the nth node from the end of the list and return the beginning of the list|
|Hard |Binary Tree Maximum Path Sum. Given the root of a non-empty binary tree, return the maximum path sum of any non-empty path.|

For each model 10 responses for each question were generated. In total there were 270 outputs. All responses were generated in C++. <br>
Data used for project --> [Here](https://github.com/mriamdkzhy/MOSS-Project-Data/tree/main/data/main-data)
### Preparing Database
The data was inputted into the MOSS program via Stanford servers. The results generated were copied into the database.
The MOSS output consisted of ‘File 1’, ‘Percentage 1’, ‘File 2’, ‘Percentage 2’ and “Lines of Code’. The database was organised in Excel by adding id, difficulty, model (type) and percentage columns to ease the process of creating graphs and finding patterns. 
Another column Average Percentage was added which was the average of the Percentage 1 and Percentage 2 columns. <br>
Project database --> [Here](https://github.com/mriamdkzhy/MOSS-Project-Data/blob/main/Data%20Collection%20-%20LLM%20Models.xlsx)
## Analysis
Main analysis was done on the 'Difference within one model', 'Difference between models' and 'Question Difficulty'.
## Summary of Findings
- Code-specific models do not necessarily provide greater variety in responses.
- Using popular models would result in more likely to be caught by MOSS (if other students were cheating by using LLMs).
- Question Difficulty does not have an effect on results.

## Other

Link to Full Report: [MOSS Project Paper](https://uao365-my.sharepoint.com/:w:/g/personal/a1884842_adelaide_edu_au/IQBHIuT1w4gDTL-wKfv2GRFpAY_EuOiQgeMdhlXdbUy4k0c?e=0LGmTf) <br>
Contact Me!: maria.madakuzhy@gmail.com





