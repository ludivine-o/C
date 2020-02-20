/*
 * light.c
 *
 *  Created on: Feb 19, 2020
 *      Author: ludivineo
 */

#include <stdbool.h>
#include <stdio.h>


bool change_state_light(state_light, user_input){

		if (state_light && user_input){
			state_light = false;
		}
		else if (state_light == false && user_input) {
			state_light = true;
		}
		return state_light;

}

int main(int argc, char* argv[]) {

	bool state_light = false;
	int user_input;

	while (true){
		printf("appuie sur un interupteur (un chiffre) :\n");
		int input_verif = scanf("%d", &user_input);

		if (input_verif == 1){
			state_light = change_state_light(state_light, user_input);
		}

		else {
			printf("appuie sur un seul putain de bouton");
		}

		if (state_light){
			printf("lumiere allumée\n");
		}
		if (state_light == false){
			printf("lumiere éteinte\n");
		}

	}
}





