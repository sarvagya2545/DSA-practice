let arr = [2,3,4,5,6,1,2,3,4];

// Time => O(n^2), Space => O(1)
function insertionSort(arr) {
    let i, j, temp, ctr;
    for(i = 1; i < arr.length; i++) {
        for(j = 0; j < i; j++) {
            if(arr[j] > arr[i])	{
                break;
            }
        }
        temp = arr[i];
        ctr = i;
        while( ctr > j ) {
            arr[ctr] = arr[ctr - 1];
            ctr--;
        }
        arr[ctr] = temp;
    }
}

// Time: min => O(n), max => O(n^2)
// Memory: O(1) 
function bubbleSort(arr) {
    let i, temp, j;
    for (j = 0; j < arr.length - 1; j++) {
        f = 0;
        for(i = 0; i < arr.length - j - 1; i++) {
            if(arr[i] > arr[i + 1]) {
                temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;

                f = 1;
            }
        }

        if(!f) break;
    }
}

function selectionSort(arr) {
    let i, j, temp;
    for(i = 0; i < arr.length; i++) {
        for(j = i + 1; j < arr.length; j++) {
            if(arr[j] < arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

function quickSort(arr) {
    
}

// insertionSort(arr);
// bubbleSort(arr);
// arr = arr.sort((a,b) => a - b);
// selectionSort(arr);
quickSort(arr);

console.log(arr);