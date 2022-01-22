gap method for sorting two sorted arrays in 0(1) space

array with start and end

gap = math.ceil((end-start)/2)
while(gap=>1){
    pointer1 = start
    pointer2 = start + gap
    while(pointer2 < end){
        if(array[pointer1]>array[pointer2]){
            swap value of pointer1 with pointer2
        }
        pointer1++
        pointer2++
    }
    int g = (gap/2)+(gap%2)
    if(g<=1) gap=0
    else gap = g
}
