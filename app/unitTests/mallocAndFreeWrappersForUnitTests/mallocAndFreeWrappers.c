#include <malloc.h>

static size_t g_numBytesAllocated = 0;

static size_t g_numBytesAllocatedBeforeTest = 0;
#define MEM_CHECK_BEFORE_TEST(num) g_numBytesAllocatedBeforeTest = num;
#define MEM_CHECK_AFTER_TEST(num) EXPECT_EQ(num,g_numBytesAllocatedBeforeTest);

// Prototypes for our hooks
void my_init_hook (void);
static void* my_malloc_hook(size_t, const void*);
static void my_free_hook(void*, const void*);

// Variables to save original hooks
static void *(*old_malloc_hook)(size_t, const void*);
static void (*old_free_hook)(void* ptr, const void* caller);

void my_init_hook(void)
{
	old_malloc_hook = __malloc_hook;
	old_free_hook = __free_hook;
	__malloc_hook = my_malloc_hook;
	__free_hook = my_free_hook;
}

static void* my_malloc_hook(size_t size, const void* caller)
{
	void* result;

	/* Restore all old hooks */
	__malloc_hook = old_malloc_hook;
	__free_hook = old_free_hook;

	/* Call recursively */
	result = malloc(size);

	/* Increment the total amount of bytes allocated */
	g_numBytesAllocated += malloc_usable_size(result);

	/* Save underlying hooks */
	old_malloc_hook = __malloc_hook;
	old_free_hook = __free_hook;

	/* Restore our own hooks */
	__malloc_hook = my_malloc_hook;
	__free_hook = my_free_hook;
	return result;
}

static void my_free_hook(void* ptr, const void* caller)
{
	/* Restore all old hooks */
	__malloc_hook = old_malloc_hook;
	__free_hook = old_free_hook;

	/* Extract the amount of bytes allocated for this block of memory */
	g_numBytesAllocated -= malloc_usable_size(ptr);

	/* Call recursively */
	free(ptr);

	/* Save underlying hooks */
	old_malloc_hook = __malloc_hook;
	old_free_hook = __free_hook;

	/* Restore our own hooks */
	__malloc_hook = my_malloc_hook;
	__free_hook = my_free_hook;
}
