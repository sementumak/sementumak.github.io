struct Stack{
  char** data = nullptr;
  int size = 0;
  int capacity = 0;
};

void Push(Stack* stack, const char* string){
  if (stack->size == stack->capacity){
    int new_capacity;
    if (stack->capacity == 0){
      new_capacity = 1;
    }
    else{
      new_capacity = stack->capacity*2;
    }
    char** new_data = new char*[new_capacity];
    for(int i = 0; i <stack->size; ++i){
      new_data[i] = stack->data[i];
    }
    delete[] stack->data;
    stack->data = new_data;
    stack->capacity = new_capacity;
  }

  int string_size = 0;
  while (string[string_size] != '\0'){
    string_size = string_size + 1;
  }
  char* copy = new char[string_size + 1];
  for(int i = 0; i < string_size + 1; i++){
    copy[i] = string[i];
  }
  stack->data[stack->size] = copy;
  stack->size = stack->size + 1;
}

void Clear(Stack* stack){
  for (int i = 0; i < stack->size; ++i) {
    delete[] stack->data[i];
  }
  delete[] stack->data;
  stack->data = nullptr;
  stack->size = 0;
  stack->capacity = 0;
}
 
void Pop(Stack* stack){ 
  if(stack->size > 0){
    stack->size = stack->size - 1;
    delete[] stack->data[stack->size];
    stack->data[stack->size] = nullptr;
  }
  if(stack->size == 0){
    Clear(stack);
  }
}

const char* Top(const Stack* stack){
  if (stack->size == 0){
    return nullptr;
  }
  else{
    return stack->data[stack->size-1];
  }
}

int Size(const Stack* stack){
  return stack->size;
}


