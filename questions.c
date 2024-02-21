/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"

void initialize_game(void) {
    // Programming category
    strcpy(questions[0].category, "programming");
    strcpy(questions[0].question, "What is a function?");
    strcpy(questions[0].answer, "procedure");
    questions[0].value = 100;
    questions[0].answered = false;

    strcpy(questions[1].category, "programming");
    strcpy(questions[1].question, "What is a variable?");
    strcpy(questions[1].answer, "data");
    questions[1].value = 200;
    questions[1].answered = false;

    strcpy(questions[2].category, "programming");
    strcpy(questions[2].question, "What is a loop?");
    strcpy(questions[2].answer, "iteration");
    questions[2].value = 300;
    questions[2].answered = false;

    // Algorithms category
    strcpy(questions[3].category, "algorithms");
    strcpy(questions[3].question, "This sorting algorithm has a worst-case time complexity of O(n log n)");
    strcpy(questions[3].answer, "What is merge");
    questions[3].value = 100;
    questions[3].answered = false;

    strcpy(questions[4].category, "algorithms");
    strcpy(questions[4].question, "What is a search algorithm?");
    strcpy(questions[4].answer, "find");
    questions[4].value = 200;
    questions[4].answered = false;

    strcpy(questions[5].category, "algorithms");
    strcpy(questions[5].question, "What is a graph algorithm?");
    strcpy(questions[5].answer, "traverse");
    questions[5].value = 300;
    questions[5].answered = false;

    // Databases category
    strcpy(questions[6].category, "databases");
    strcpy(questions[6].question, "What is a table?");
    strcpy(questions[6].answer, "relation");
    questions[6].value = 100;
    questions[6].answered = false;

    strcpy(questions[7].category, "databases");
    strcpy(questions[7].question, "What is a query?");
    strcpy(questions[7].answer, "request");
    questions[7].value = 200;
    questions[7].answered = false;

    strcpy(questions[8].category, "databases");
    strcpy(questions[8].question, "What is a record?");
    strcpy(questions[8].answer, "entry");
    questions[8].value = 300;
    questions[8].answered = false;

    // Set the value for the last question
    questions[11].value = 300;
}


void display_categories(void) {
    char questionCategories[12][20];

	for (int i = 0; i < 12; i++) {
		
		if (questions[i].answered == false) 
			printf(questionCategories[i], 20, "%d", questions[i].value);
			
		else
            strcpy(questionCategories[i], "   ");
		
			
	}
	printf("   %s   |   %s   |   %s   \n", categories[0], categories[1], categories[2]);
	printf("  -------------------------------------------------\n");

	printf("      %s      |     %s     |         %s   \n", questionCategories[0], questionCategories[1], questionCategories[2]);
	printf("  -------------------------------------------------\n");
	
	printf("      %s      |     %s     |         %s   \n", questionCategories[3], questionCategories[4], questionCategories[5]);
	printf("  -------------------------------------------------\n");
	
	printf("      %s      |     %s     |         %s   \n", questionCategories[6], questionCategories[7], questionCategories[8]);
	printf("  -------------------------------------------------\n");

	printf("      %s      |     %s     |         %s   \n", questionCategories[9], questionCategories[10], questionCategories[11]);
	printf("  -------------------------------------------------\n");
}

void display_question(char *category, int value) {
    for (int i = 0; i < NUM_QUESTIONS; ++i) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            printf("Category: %s\n", questions[i].category);
            printf("Question for $%d: %s\n", questions[i].value, questions[i].question);
            return;
        }
    }
}

bool valid_answer(char *category, int value, char *answer) {
    for (int i = 0; i < NUM_QUESTIONS; ++i) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            questions[i].answered = true;
            return strcmp(questions[i].answer, answer) == 0;
        }
    }
    return false; // Question not found
}

bool already_answered(char *category, int value) {
    for (int i = 0; i < NUM_QUESTIONS; ++i) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            return questions[i].answered;
        }
    }
    return true; // Question not found
}

