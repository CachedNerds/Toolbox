template <typename OutputType>
BasicSink<OutputType>::BasicSink (void)
: _outputVisitor ()
{

}

template <typename OutputType>
BasicSink<OutputType> & BasicSink<OutputType>::operator << (const Output & output)
{
  this->output (boost::apply_visitor (_outputVisitor, output));
  return *this;
}