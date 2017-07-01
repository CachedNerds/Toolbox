template <typename OutputType>
BasicSink<OutputType> & BasicSink<OutputType>::operator << (const OutputType & output)
{
  this->output (output);
  return *this;
}

template <typename OutputType>
BasicSink<OutputType> & BasicSink<OutputType>::operator << (const Output<OutputType> & output)
{
  this->output (output.getOutput ());
  return *this;
}