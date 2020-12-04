#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <assert.h>

#include <uk/config.h>
#include <uk/essentials.h>

#include <test_suite_glue.h>

int *__errno_location(void)
{
	return NULL;
}

unsigned short int **__ctype_b_loc(void)
{
	return NULL;
}

void setprogname(const char *progname)
{
	strncpy(program_invocation_short_name, progname, 255);
}

const char *getprogname(void)
{
	const char *name;

	name = program_invocation_name;
	assert(name);

	return name;
}

int stat64(const char *path, struct stat *buf)
{
	return stat(path, buf);
}

/* No varargs support */
int open64(const char *pathname, int oflag, ...)
{
	return open(pathname, oflag);
}

/* No varargs support */
int fcntl64(int fd, int cmd, ...)
{
	return fcntl(fd, cmd);
}

FILE *fopen64(const char *filename, const char *type)
{
	return fopen(filename, type);
}

int mkstemp64(char *template)
{
	return mkstemp(template);
}

/* Can run all the tests, or just some of them based on preferances */
int libp11kit_test_main(int argc, char *argv[])
{
	int test_counter = 0;
	int error_counter = 0;
	int rc;

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_ARGV
	test_counter++;
	printf("Running test_argv ....................\n");
	rc = test_argv_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_ARRAY
	test_counter++;
	printf("Running test_array ....................\n");
	rc = test_array_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_ATTRS
	test_counter++;
	printf("Running test_attrs ....................\n");
	rc = test_attrs_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_BUFFER
	test_counter++;
	printf("Running test_buffer ....................\n");
	rc = test_buffer_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_COMPAT
	test_counter++;
	printf("Running test_compat ....................\n");
	rc = test_compat_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_CONSTANTS
	test_counter++;
	printf("Running test_constants ....................\n");
	rc = test_constants_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_DEPRECATED
	test_counter++;
	printf("Running test_deprecated ....................\n");
	rc = test_deprecated_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_DICT
	test_counter++;
	printf("Running test_dict ....................\n");
	rc = test_dict_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_FILTER
	test_counter++;
	printf("Running test_filter ....................\n");
	rc = test_filter_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_HASH
	test_counter++;
	printf("Running test_hash ....................\n");
	rc = test_hash_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_INIT
	test_counter++;
	printf("Running test_init ....................\n");
	rc = test_init_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_ITER
	test_counter++;
	printf("Running test_iter ....................\n");
	rc = test_iter_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_LEXER
	test_counter++;
	printf("Running test_lexer ....................\n");
	rc = test_lexer_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_LOG
	test_counter++;
	printf("Running test_log ....................\n");
	rc = test_log_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_MANAGED
	test_counter++;
	printf("Running test_managed ....................\n");
	rc = test_managed_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_MESSAGE
	test_counter++;
	printf("Running test_message ....................\n");
	rc = test_message_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_MODULES
	test_counter++;
	printf("Running test_modules ....................\n");
	rc = test_modules_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_PATH
	test_counter++;
	printf("Running test_path ....................\n");
	rc = test_path_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_PIN
	test_counter++;
	printf("Running test_pin ....................\n");
	rc = test_pin_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_PROGNAME
	test_counter++;
	printf("Running test_progname ....................\n");
	rc = test_progname_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_PROXY
	test_counter++;
	printf("Running test_proxy ....................\n");
	rc = test_proxy_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_RPC
	test_counter++;
	printf("Running test_rpc ....................\n");
	rc = test_rpc_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_RUNTIME
	test_counter++;
	printf("Running test_runtime ....................\n");
	rc = test_runtime_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_SERVER
	test_counter++;
	printf("Running test_server ....................\n");
	rc = test_server_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_TESTS
	test_counter++;
	printf("Running test_tests ....................\n");
	rc = test_tests_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_TRANSPORT
	test_counter++;
	printf("Running test_transport ....................\n");
	rc = test_transport_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_URI
	test_counter++;
	printf("Running test_uri ....................\n");
	rc = test_uri_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_URL
	test_counter++;
	printf("Running test_url ....................\n");
	rc = test_url_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_UTIL
	test_counter++;
	printf("Running test_util ....................\n");
	rc = test_util_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_VIRTUAL
	test_counter++;
	printf("Running test_virtual ....................\n");
	rc = test_virtual_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

#if CONFIG_ALL_TEST_CASES || CONFIG_TESTS_CONF
	test_counter++;
	printf("Running test_conf ....................\n");
	rc = test_conf_main(argc, argv);
	if (rc == 0) {
		printf("PASS\n");
	} else {
		printf("FAIL\n");
		error_counter++;
	}
#endif

	printf("Total tests : %d\n", test_counter);
	printf("Total errors: %d\n", error_counter);

	return error_counter;
}
