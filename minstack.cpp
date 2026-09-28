#include<iostream.h>
#include<conio.h>

#define MAX 100

class Stack {
 int stack[MAX];
 int minStack[MAX];
 int top;
 int minTop;

public:
 Stack() {
  top=-1;
  minTop=-1;
 }

 void push(int value) {
  if(top==MAX-1) {
   cout<<"\nStack Overflow";
   return;
  }

  top++;
  stack[top]=value;

  if(minTop==-1||value<=minStack[minTop]) {
   minTop++;
   minStack[minTop]=value;
  }

  cout<<"\n"<<value<<" pushed";
 }

 void pop() {
  if(top==-1) {
   cout<<"\nStack Underflow";
   return;
  }

  if(stack[top]==minStack[minTop])
   minTop--;

  cout<<"\n"<<stack[top]<<" popped";
  top--;
 }

 void min() {
  if(minTop==-1) {
   cout<<"\nStack is empty";
   return;
  }

  cout<<"\nMinimum value = "<<minStack[minTop];
 }

 void display() {
  if(top==-1) {
   cout<<"\nStack is empty";
   return;
  }

  cout<<"\nStack: ";

  for(int i=top;i>=0;i--)
   cout<<stack[i]<<" ";
 }
};

void main() {
 clrscr();

 Stack s;
 s.push(10);
 s.push(3);
 s.push(4);
 s.push(1);
 s.min();
 s.pop();
 s.pop();
 s.min();

 getch();
}