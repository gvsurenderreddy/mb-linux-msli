/*
 * qspi.h
 */

#define DEBUG 1

#if defined(DEBUG)
#define DBG(a...)   fprintf(stderr, a)
#else
#define DBG(a...)
#endif

#define PRINTV(a...)   if (opt_verbose) fprintf (stderr, a)

#if defined(_DECLARE_)
# define EXTERN
#else
# define EXTERN extern
#endif

/****** program options: *****************************************************/

EXTERN char *opt_port;
EXTERN int opt_polarity;
EXTERN int opt_phase;
EXTERN int opt_channel;
EXTERN int opt_bits;
EXTERN int opt_cmd_shift;
EXTERN int opt_ret_shift;
EXTERN int opt_baud;
EXTERN int opt_N;
EXTERN int opt_continuous;
EXTERN int opt_help;
EXTERN int opt_verbose;

#if defined(_DECLARE_)
static const struct option options[] = {
	{"port", required_argument, NULL, 'p'},
	{"polarity", required_argument, NULL, 'l'},
	{"phase", required_argument, NULL, 'a'},
	{"channel", required_argument, NULL, 'c'},
	{"bits", required_argument, NULL, 'b'},
	{"cmd_shift", required_argument, NULL, 'm'},
	{"ret_shift", required_argument, NULL, 'r'},
	{"baud", required_argument, NULL, 'd'},
	{"samples", required_argument, NULL, 'n'},
	{"continuous", no_argument, NULL, 't'},
	{"verbose", no_argument, NULL, 'v'},
	{"help", no_argument, NULL, 'h'},
	{NULL, 0, NULL, 0}
};

/* #else */
/* extern const struct option options[]; */

#endif

/* NOTE that the help MUST keep pace with the above option definitions: */
#if defined(_DECLARE_)
char *option_help[] = {
	"(string) linux qspi device file",
	"(int) clock polarity (1 = inactive high)",
	"(int) clock phase (1 = data output on leading edge and sampled on following edge)",
	"(int) MCP3202 channel number (0 or 1)",
	"(int) data bits per transfer (8 to 16)",
	"(int) bits to SHR MCP command",
	"(int) bits to SHR result",
	"(int) bits per second (qspi clock)",
	"(int) number of samples to read",
	"print continuously (instead of buffering first)",
	"produce verbose output on stderr",
	"print usage",
	NULL
};

/* The option string is autogenerated: */
#define N_OPTIONS  (sizeof (options) / sizeof (options[0]))
/* allocate worst case option string based on
 * the longopts present + possibly '::' after each one */
char option_string[3 * N_OPTIONS];

#else
extern char *option_help[];

#endif

/****** prototypes: **********************************************************/

EXTERN int spiRead(int port_fd, uint8_t registerIndex);

EXTERN void usage(void);
EXTERN int build_option_string(struct option *longopts, char *option_string);
EXTERN void init_options(void);
EXTERN int decode_args(int argc, char *argv[]);

