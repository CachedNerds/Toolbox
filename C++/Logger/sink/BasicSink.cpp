template <typename OutputType>
BasicSink<OutputType> & BasicSink<OutputType>::operator << (const Output & output)
{
  this->output (OutputVariant::get (output));
  return *this;
}