## C Helper Function
A bunch of helper functions to save time.

### Helpers:
#### Dynamic Array
```c
typedef struct {
    void* data;
    size_t element_size;
    size_t size;
    size_t capacity;
} DynamicArray;

DynamicArray* dynamic_array_create(size_t element_size);
void dynamic_array_free(DynamicArray* array);
bool dynamic_array_append(DynamicArray* array, const void* element);
void* dynamic_array_get(DynamicArray* array, size_t index);
bool dynamic_array_set(DynamicArray* array, size_t index, const void* element);
bool dynamic_array_remove(DynamicArray* array, size_t index);
bool dynamic_array_resize(DynamicArray* array, size_t new_capacity);
void dynamic_array_clear(DynamicArray* array);
void dynamic_array_copy(DynamicArray* dest, const DynamicArray* src);
bool dynamic_array_is_full(DynamicArray* array);
```
#### File Utils
```c
// File operations
bool file_exists(const char* filename);
bool file_read(const char* filename, void* buffer, size_t size);
bool file_write(const char* filename, const void* data, size_t size);
bool file_append(const char* filename, const void* data, size_t size);
bool file_delete(const char* filename);
bool file_clear(const char* filename);

// Struct to hold the result of directory listing
typedef struct {
    char** paths;
    size_t count;
} DirectoryList;

// Directory operations
bool directory_exists(const char* dirname);
bool directory_create(const char* dirname);
bool directory_remove(const char* dirname);
DirectoryList directory_list(const char* dirname);
void free_directory_list(DirectoryList* dir_list);

#endif
```
#### Progress Bar
```c
void progress_bar(double percentage, bool withColor);
```
#### String Utils
```c
char *trim(char *str);
char *to_upper(char *str);
char *to_lower(char *str);
```
#### Safe Input
```c
bool input_int(int *value);
bool input_long(long *value);
bool input_long_long(long long *value);
bool input_unsigned_int(unsigned int *value);
bool input_unsigned_long(unsigned long *value);
bool input_unsigned_long_long(unsigned long long *value);
bool input_float(float *value);
bool input_double(double *value);
bool input_long_double(long double *value);
bool input_string(char *buffer, size_t size);
```
#### Math
##### Random:
Supported data types:
- `int`
- `unsigned int`
- `float`
- `long`
- `unsigned long`
- `long long`
- `unsigned long long`
- `double`

All functions follow the general form: `[T] random_[T]([T] min, [T] max);`. Where `[T]` represents one of the supported data types listed above.
A random seed is initialized automatically (via `srand(time(NULL))`).







