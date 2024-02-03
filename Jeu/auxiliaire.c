#ifndef __AUXILIAIRE_H__
#define __AUIXLIAIRE_H__








int checkNumber(int num, int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return 0; // number already exists
        }
    }
    return 1; // number doesn't exist
}

















#endif