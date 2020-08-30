// 2020/08/28 - Created by netcan: https://github.com/netcan
// This example demonstrates how to use 'dump' method to inspect
// a taskflow graph.
// use task dsl

#include <taskflow/taskflow.hpp>
#include <taskflow/dsl/task_dsl.hpp> // for support dsl

int main(){
  tf::Taskflow tf("Visualization Demo");

  // ------------------------------------------------------
  // Static Tasking
  // ------------------------------------------------------
  def_task(A, { return []() { std::cout << "TaskA\n"; }; });
  def_task(B, { return []() { std::cout << "TaskB\n"; }; });
  def_task(C, { return []() { std::cout << "TaskC\n"; }; });
  def_task(D, { return []() { std::cout << "TaskD\n"; }; });
  def_task(E, { return []() { std::cout << "TaskE\n"; }; });

  taskbuild(
    chain(task(A)
        -> fork(B, C)
        -> task(D)),
    chain(merge(A, B)
        -> task(E))
  ) {tf};

  // std::cout << "[dump without name assignment]\n";
  tf.dump(std::cout);

  // TODO: support set name
  // std::cout << "[dump with name assignment]\n";
  // A.name("A");
  // B.name("B");
  // C.name("C");
  // D.name("D");
  // E.name("E");
  // tf.dump(std::cout);

  // ------------------------------------------------------
  // Dynamic Tasking
  // ------------------------------------------------------


  return 0;
}


