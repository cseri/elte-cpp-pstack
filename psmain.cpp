#include "pstack.h"
#include <iostream>
#include <algorithm>
#include <string>

struct StringSizeLess
{
  bool operator()(const std::string& a,
                  const std::string& b) const
  {
    return a.size() < b.size();
  }
};

struct Print
{
  void operator()(const int& i) const
  {
    std::cout << i << " ";
  }
};

const int max = 1000;

int main()
{
  int yourMark = 1;
  /* 2-es */
  priority_stack<double> sd;
  for(int i = 0; i < max; ++i)
    sd.push(i, 6.7);

  priority_stack<int> si;
  si.push(5, 2);
  si.push(5, 3);
  si.push(4, 7);
  const priority_stack<int> csi = si;
  if (1 == sd.size(0) && 3 == csi.top())
  {
    yourMark = csi.size(5);
  }
  // */

  /* 3-as */
  si.top() = 5;
  if (5 == si.top())
    yourMark = csi.size();
  // */

  /* 4-es */
  si.pop();
  std::cout << si.top() << std::endl;
  si.pop();
  std::cout << si.top() << std::endl;

  priority_stack<int, double> sid;
  sid.push(6.5, 4);

  if (si.size() == sid.size())
  {
    yourMark = sid.top();
  }
  // */

  /* 5-os */
  priority_stack<int, std::string, StringSizeLess> strst;
  strst.push("abcdg", 5);
  strst.push("dfg", 4);
  if (2 == strst.size())
    yourMark = strst.top();
  // */
  std::cout << "Your mark is " << yourMark
            << std::endl;

  /* Iterator */
  std::cout << "Iterator test: " << std::endl;

  for (priority_stack<int>::const_iterator it =
      csi.begin(); it != csi.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  for (priority_stack<int, std::string, StringSizeLess>::const_iterator it =
      strst.begin(); it != strst.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  std::for_each(strst.begin(), strst.end(), Print());
  std::cout << std::endl;
  // */
 
  return 0;
}
