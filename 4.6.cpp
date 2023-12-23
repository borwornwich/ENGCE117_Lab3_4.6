#include <stdio.h>
#include <string.h>

struct studentNode {
	char name[ 20 ] ;
	int age ;
	char sex ;
	float gpa ;
	struct studentNode *next ;
} ;

void SaveNode( struct studentNode *child, char n[], int a, char s, float g ) ;
void GoNext2( struct studentNode ***walk ) ;

int main() {
	struct studentNode *start, *now1, **now2 ;
	start = new struct studentNode ;
	SaveNode( start, "one", 6, 'M', 3.11 ) ;
	 
	start->next = new struct studentNode ;
	SaveNode( start->next, "two", 8, 'F', 3.22 ) ;
	 
	start->next->next = new struct studentNode ;
	SaveNode( start->next->next, "three", 10, 'M', 3.33 ) ;
	
	start->next->next->next = new struct studentNode ;
	SaveNode( start->next->next->next, "four", 12, 'F', 3.44 ) ;
	
	now1 = start ;
	now2 = &start ;
	
	GoNext2( &now2 ) ;
	printf( "name: %s \n", (*now2)->name ) ;
	printf( "age: %d \n", (*now2)->age ) ;
	printf( "sex: %c \n", (*now2)->sex ) ;
	printf( "gpa: %.2f \n", (*now2)->gpa ) ;
	
//	while ( now1 != NULL ) {
//		printf( " %s \n", now1->name ) ;
//		printf( " %d \n", now1->age ) ;
//		printf( " %c \n", now1->sex ) ;
//		printf( " %.2f \n", now1->gpa ) ;
//		printf( "\n" ) ;
//		
//		GoNext1( now2 ) ;
//		now1 = *now2 ;
//	}

	return 0 ;
}//end function

void SaveNode( struct studentNode *child, char n[], int a, char s, float g ) {
	strcpy( child->name, n ) ;
	child->age = a ;
	child->sex = s ;
	child->gpa = g ;
}//end function

void GoNext2( struct studentNode ***walk ) {
	if ( (**walk)->next != NULL ) {
        **walk = (**walk)->next ;
    }
}
