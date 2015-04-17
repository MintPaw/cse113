struct bit_t
{
	unsigned char n;
	struct bit_t *prev;
	struct bit_t *next;
};

struct cpu_t
{
	int word_size;
	int unsign; //0 -- signed, 1 for unsigned
	// flags
	int overflow;
	int carry;
	int sign;
	int parity;
	int zero;
	struct bit_t *r1_head;
	struct bit_t *r1_tail;
	struct bit_t *r2_head;
	struct bit_t *r2_tail;
	struct bit_t *r3_head;
	struct bit_t *r3_tail;
};

void get_real_char(char *c);
struct bit_t *string_to_bit_list(char *string, int size);
struct bit_t *get_tail(struct bit_t *head);
void print_node(struct bit_t *node);
void print_node_neat(struct bit_t *node);
void print_register(struct bit_t *head);
void print_register_neat(struct bit_t *head);
struct bit_t *empty_bit_list(int size);
void add(struct cpu_t *cpu);
void subtract(struct cpu_t *cpu);
char get_value(struct bit_t *head, int index);
void set_value(struct bit_t *head, int index, char value);
void set_flags(struct cpu_t *cpu);
void print_flags(struct cpu_t *cpu);
void complement_r2(struct cpu_t *cpu);
struct bit_t *clone_list(struct bit_t *head);
int add_registers(struct bit_t *head1,
				  struct bit_t *head2,
				  struct bit_t *head3,
				  int size);
void and(struct cpu_t *cpu);
void or(struct cpu_t *cpu);
void xor(struct cpu_t *cpu);
void print_dashes(int size);
int register_to_int(struct bit_t *head, char unsign);