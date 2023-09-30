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
  t_frame frame;

  create_frame(&frame);
  validate_args(argc, argv, &frame);
  if (!is_queue_sorted(&frame.args_queue)) {
    populate_stack(&frame);

    if (frame.size <= 3) {
      sort_three(&frame.a, 'a');
    } else {
      printf("%d yo\n", frame.size);
      sort(&frame);
    }
    print_stack(frame.a);
    clean_stack(&frame.a);

    // diagnose(&a, &b);
  }

  return (0);
}