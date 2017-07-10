template <typename OutputType>
BasicSink<OutputType> & BasicSink<OutputType>::operator << (const OutputVisitor & output)
{
  this->output (Output::get (output));
  return *this;
}