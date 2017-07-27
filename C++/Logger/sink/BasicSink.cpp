template <typename OutputType>
BasicSink <OutputType> & BasicSink <OutputType>::operator << (const OutputType & output)
{
  this->output (output);
  return *this;
}
