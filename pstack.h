#ifndef PSTACK_H_
#define PSTACK_H_

#include <map>
#include <vector>
#include <functional>

template <typename T, typename Prio = int, typename Comp = std::less<Prio> >
class priority_stack
{
  std::map<Prio, std::vector<T>, Comp> m;

  typedef typename std::map<Prio, std::vector<T> >::const_iterator map_c_it;

public:

  priority_stack(Comp comp = Comp()) : m(comp) { }

  void push(const Prio& prio, const T& e)
  {
    m[prio].push_back(e);
  }

  const T& top() const
  {
    return (--m.end())->second.back();
  }

  T& top()
  {
    return (--m.end())->second.back();
  }

  std::size_t size(const Prio& prio) const
  {
    map_c_it it = m.find(prio);
    if (it == m.end()) {
      return 0;
    } else {
      return it->second.size();
    }
  }

  std::size_t size() const
  {
    std::size_t sum = 0;
    for (map_c_it it = m.begin(); it != m.end(); ++it)
    {
      sum += it->second.size();
    }
    return sum;
  }

  void pop()
  {
    (--m.end())->second.pop_back();
    if ((--m.end())->second.empty()) {
      m.erase(--m.end());
    }
  }

};

#endif // PSTACK_H_
