#include "push_swap.h"
#include <stdio.h>

// static void diagnose(t_stack *a, t_stack *b) {
//   printf("Initial A:\n");
//   print_stack(a);

//   printf("After swapping A\n");
//   swap(a, 'a', 1);
//   print_stack(a);

//   push(a, b, 'b');
//   push(a, b, 'b');
//   push(a, b, 'b');
//   printf("A After pushing 3 items\n");
//   print_stack(a);
//   printf("B After pushing 3 items\n");
//   print_stack(b);

//   rrr(a, b);
//   printf("A After r_rotating \n");
//   print_stack(a);
//   printf("B After r_rotating \n");
//   print_stack(b);
//   clean_stack(a);
//   clean_stack(b);
// }

int main(int argc, char **argv) {
  t_stack a;
  t_stack b;
  t_args_queue args_queue;

  validate_args(argc, argv, &args_queue);
  if (!is_queue_sorted(&args_queue)) {
    init_and_populate_stack(&a, &b, &args_queue);
    if (a.size <= 3) {
      sort_three(&a, 'a');
    } else {
      sort(&a, &b);
    }
    // print_stack(&a);
    clean_stack(&a);

    // diagnose(&a, &b);
  }

  return (0);
}