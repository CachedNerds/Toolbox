template <typename OutputType>
const OutputType OutputVisitor<OutputType>::operator () (const OutputType & output) const
{
  return output;
}

template <typename OutputType>
const OutputType OutputVisitor<OutputType>::operator () (const Outputable<OutputType> & output) const
{
  return output.toOutput ();
}