#include <stdio.h>
//#include "stack1.h"
//#include "stack2.h"
#include "stack3.h"

#define MAX_PUSH 10




int main() {
	stack s;

    for (int i = 0; i < MAX_PUSH; i++) {
        int push_result = s.push(i);

        if (push_result != stack::SUCCESS) {
            printf("Failed to push element %d, error code %d\n", i, push_result);
            break;
        }

        int top_element;

        int top_result = s.top(top_element);
        if (top_result != stack::SUCCESS) {
            printf("Failed to get top element, error code %d\n", top_result);
            break;
        }

        printf("top = %d\n", top_element);
    }

	//for (int i = 0; i < MAX_PUSH; i++) {
	//
	//	s.push(i);
	//	printf("top = %d\n", s.top());

	//}
}