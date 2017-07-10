template <typename ResultType>
const ResultType Result<ResultType>::VariantVisitor::operator () (const ResultType & subject) const
{
  return subject;
}

template <typename ResultType>
const ResultType Result<ResultType>::VariantVisitor::operator () (const ConvertibleTo<ResultType> & subject) const
{
  return subject.convert ();
}

template <typename ResultType>
const ResultType Result<ResultType>::get (const typename Result<ResultType>::Variant & result)
{
  static VariantVisitor variantVisitor;
  return boost::apply_visitor (variantVisitor, result);
}