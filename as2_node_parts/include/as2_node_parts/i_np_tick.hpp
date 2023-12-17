#ifndef I_NP_TICK__HPP
#define I_NP_TICK__HPP

template<typename InputState, typename InnerState>
class i_np_tick
{
public:
  virtual ~i_np_tick() = default;

  virtual void tick(const InputState &, InnerState &) = 0;
};

#endif  // I_NP_TICK__HPP
