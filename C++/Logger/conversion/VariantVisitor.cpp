template <typename ResultType>
const ResultType VariantVisitor<ResultType>::operator () (const ResultType & subject) const
{
  return subject;
}

template <typename ResultType>
const ResultType VariantVisitor<ResultType>::operator () (const ConvertibleTo<ResultType> & subject) const
{
  return subject.convert ();
}