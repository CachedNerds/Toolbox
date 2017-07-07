template <typename ResultType>
const ResultType ConversionVisitor<ResultType>::operator () (const ResultType & subject) const
{
  return subject;
}

template <typename ResultType>
const ResultType ConversionVisitor<ResultType>::operator () (const ConvertibleTo<ResultType> & subject) const
{
  return subject.convert ();
}