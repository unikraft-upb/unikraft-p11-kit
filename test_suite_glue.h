#ifndef __TEST_SUITE_GLUE__LIBP11KIT_H__
#define __TEST_SUITE_GLUE__LIBP11KIT_H__

/* Workaround for missing  set/getprogname */
char program_invocation_short_name[256] = "mock_name";
char program_invocation_name[256] = "mock_name";

extern char p11_my_progname[256];

int libp11kit_test_main(int argc, char *argv[]);

int test_argv_main(int argc, char *argv[]);
int test_array_main(int argc, char *argv[]);
int test_attrs_main(int argc, char *argv[]);
int test_buffer_main(int argc, char *argv[]);
int test_compat_main(int argc, char *argv[]);
int test_constants_main(int argc, char *argv[]);
int test_deprecated_main(int argc, char *argv[]);
int test_dict_main(int argc, char *argv[]);
int test_filter_main(int argc, char *argv[]);
int test_hash_main(int argc, char *argv[]);
int test_iter_main(int argc, char *argv[]);
int test_init_main(int argc, char *argv[]);
int test_lexer_main(int argc, char *argv[]);
int test_log_main(int argc, char *argv[]);
int test_managed_main(int argc, char *argv[]);
int test_message_main(int argc, char *argv[]);
int test_modules_main(int argc, char *argv[]);
int test_path_main(int argc, char *argv[]);
int test_pin_main(int argc, char *argv[]);
int test_progname_main(int argc, char *argv[]);
int test_proxy_main(int argc, char *argv[]);
int test_rpc_main(int argc, char *argv[]);
int test_runtime_main(int argc, char *argv[]);
int test_server_main(int argc, char *argv[]);
int test_tests_main(int argc, char *argv[]);
int test_transport_main(int argc, char *argv[]);
int test_uri_main(int argc, char *argv[]);
int test_url_main(int argc, char *argv[]);
int test_util_main(int argc, char *argv[]);
int test_virtual_main(int argc, char *argv[]);
int test_conf_main(int argc, char *argv[]);

#endif /* __TEST_SUITE_GLUE__LIBP11KIT_H__ */
