/*
 * cinderblocks.c
 *
 *  Created on: Feb 19, 2020
 *      Author: ludivineo
 */
#include <stdbool.h>
#include <stdio.h>


char sort_cinderblocks(float P_test,float  L_test,float  M_test,float  H_test){
    float P = 19000;
    float H = 200;
    float M = 200;
    float L = 500;
    char category;

    if (P_test == P){
       if ((L_test == L && M_test == M) || (M_test == M && H_test == H) || (L_test == L && H_test == H)){
           category = 'A';
       }
       else{
    	   category = 'B';
       }
    }
    if (P_test != P){
       if ((L_test != L && M_test != M) || (M_test != M && H_test != H) || (L_test != L && H_test != H)){
    	   category = 'C';
       }
        else{
        	category = 'B';
        }
    }
    return category;
}


float calcul_tolerance_max(float tolerance, float value){
	float result_tolerance_max = value + (value*(tolerance/100));
	return result_tolerance_max;
	}


float calcul_tolerance_min(float tolerance, float value){
	float result_tolerance_min = value - (value*(tolerance/100));
	return result_tolerance_min;
	}


bool compare_value(float model_value, float test_value, float tolerance){
	if (test_value < calcul_tolerance_max(tolerance, model_value) && test_value > calcul_tolerance_min(tolerance, model_value)){
		return true;
	}
	else{
		return false;
	}
}


char categorize_cinderblocks_tolerance(float P_test,float  L_test,float  M_test,float  H_test, float tolerance){
	float P= 19000;
    float H = 200;
    float M = 200;
    float L = 500;

    bool P_is_right = compare_value(P, P_test, tolerance);
    bool H_is_right = compare_value(H, H_test, tolerance);
    bool M_is_right = compare_value(M, M_test, tolerance);
    bool L_is_right = compare_value(L, L_test, tolerance);

    char category;

    if (P_is_right){
       if ((L_is_right && M_is_right) || (M_is_right && H_is_right) || (L_is_right && H_is_right)){
           category = 'A';
       }
       else{
    	   category = 'B';
       }
    }
    if (!(P_is_right)){
       if ((!(L_is_right) && !(M_is_right)) || (!(M_is_right) && !(H_is_right)) || (!(L_is_right) && !(H_is_right))){
    	   category = 'C';
       }
        else{
        	category = 'B';
        }
    }
    return category;
}



int main(int argc, char* argv[]) {
	float tolerance = 2;
    float P_test = 19100;
    float H_test = 200;
    float M_test = 200;
    float L_test = 500;
    char category_test = categorize_cinderblocks_tolerance(P_test, L_test, M_test, H_test, tolerance);
    printf("la categorie du parpaing testé est : %c\n",category_test);

}
