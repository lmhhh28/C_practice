#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100
#define MAX_K 100

typedef struct {
    int number;
    int index;
} Car;

typedef struct {
    Car* stack;
    int top;
    int capacity;
} BufferTrack;

BufferTrack* createBufferTrack(int capacity) {
    BufferTrack* buffer = (BufferTrack*)malloc(sizeof(BufferTrack));
    buffer->stack = (Car*)malloc(capacity * sizeof(Car));
    buffer->top = -1;
    buffer->capacity = capacity;
    return buffer;
}

int isEmpty(BufferTrack* buffer) {
    return buffer->top == -1;
}

Car* getTop(BufferTrack* buffer) {
    if (isEmpty(buffer)) return NULL;
    return &buffer->stack[buffer->top];
}

void push(BufferTrack* buffer, Car car) {
    if (buffer->top < buffer->capacity - 1) {
        buffer->stack[++buffer->top] = car;
    }
}

Car pop(BufferTrack* buffer) {
    if (!isEmpty(buffer)) {
        return buffer->stack[buffer->top--];
    }
    Car invalid = {-1, -1};
    return invalid;
}

void destroyBufferTrack(BufferTrack* buffer) {
    free(buffer->stack);
    free(buffer);
}

void railRearrangement(int n, int k, Car* cars) {
    BufferTrack** buffers = (BufferTrack**)malloc(k * sizeof(BufferTrack*));
    for (int i = 0; i < k; i++) {
        buffers[i] = createBufferTrack(n);
    }
    
    int next = 1;
    int* result = (int*)malloc(n * sizeof(int));
    int result_count = 0;
    int possible = 1;
    
    for (int i = 0; i < n && possible; i++) {
        Car current_car = cars[i];
        
        if (current_car.number == next) {
            result[result_count++] = current_car.index;
            next++;
            
            int found;
            do {
                found = 0;
                for (int j = 0; j < k; j++) {
                    Car* top_car = getTop(buffers[j]);
                    if (top_car != NULL && top_car->number == next) {
                        Car popped = pop(buffers[j]);
                        result[result_count++] = popped.index;
                        next++;
                        found = 1;
                        break;
                    }
                }
            } while (found);
        } else {
            int best_buffer = -1;
            int min_top_number = n + 2;
            
            for (int j = 0; j < k; j++) {
                Car* top_car = getTop(buffers[j]);
                if (top_car != NULL) {
                    if (top_car->number > current_car.number) {
                        if (top_car->number < min_top_number) {
                            min_top_number = top_car->number;
                            best_buffer = j;
                        }
                    }
                }
            }
            
            if (best_buffer == -1) {
                for (int j = 0; j < k; j++) {
                    if (isEmpty(buffers[j])) {
                        best_buffer = j;
                        break;
                    }
                }
            }
            
            if (best_buffer != -1) {
                push(buffers[best_buffer], current_car);
            } else {
                possible = 0;
            }
        }
    }
    
    while (possible && next <= n) {
        int found = 0;
        for (int j = 0; j < k; j++) {
            Car* top_car = getTop(buffers[j]);
            if (top_car != NULL && top_car->number == next) {
                Car popped = pop(buffers[j]);
                result[result_count++] = popped.index;
                next++;
                found = 1;
                break;
            }
        }
        if (!found) {
            possible = 0;
        }
    }
    
    if (possible && result_count == n) {
        for (int i = 0; i < result_count; i++) {
            printf("%d\n", result[i]);
        }
    } else {
        printf("错误：任务不可能完成。\n");
    }
    
    free(result);
    for (int i = 0; i < k; i++) {
        destroyBufferTrack(buffers[i]);
    }
    free(buffers);
}

int main() {
    int n, k;
    
    if (scanf("%d %d", &n, &k) != 2) {
        printf("错误：任务不可能完成。\n");
        return 0;
    }
    
    Car* cars = (Car*)malloc(n * sizeof(Car));
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &cars[i].number) != 1) {
            printf("错误：任务不可能完成。\n");
            free(cars);
            return 0;
        }
        cars[i].index = i;
    }
    
    railRearrangement(n, k, cars);
    
    free(cars);
    return 0;
}
