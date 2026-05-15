/**
 * @param {number[]} arr
 * @return {void} Do not return anything, modify arr in-place instead.
 */
var duplicateZeros = function(arr) {
    let n = arr.length;

let zeroes = arr.filter(x => x == 0).length;

let i = n - 1;
let j = n + zeroes - 1;

while(i >= 0){

    if(j < n) arr[j] = arr[i];

    if(arr[i] == 0){

        j--;

        if(j < n) arr[j] = arr[i];
    }

    i--;
    j--;
}
};