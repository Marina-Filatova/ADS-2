// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
int count = 0;
for (int i = 0; i < len - 1; i++) {
for (int j = i + 1; j < len; j++) {
if ((arr[i] + arr[j]) == value) count++;
}
}
return count;
}

int countPairs2(int *arr, int len, int value) {
int count = 0, left = 0, right = len;
while (true)
{
if ((arr[right] > value) || (arr[left] + arr[right] > value)) {
right--;
}
else {
break;
}
}

len = right;
for (int i = 0; i < len-1; i++) {
for (int j = len; j > i; j--) {
if (arr[i] + arr[j] == value)
count++;
}
}
return count;
}

int countPairs3(int *arr, int len, int value) {
int count = 0, left = 0, right = len;
while (true)
{
if ((arr[right] > value) || (arr[left] + arr[right] > value)) {
right--;
}
else {
break;
}
}
  
len = right;
for (int i = 0; i < len; i++) {
left = i + 1, right = len - 1;
int f = 0;
while (left < right) {
int middle = (left + right) / 2;
if (arr[middle] < (value - arr[i]))
left = middle + 1;
else
right = middle;
}
while (arr[left] == (value - arr[i])) {
f++;
left++;
}
count += f;
}
return count;
}
