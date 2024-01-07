def qsort(array)
  return array if array.length <= 1

  pivot = array.shift
  left, right = array.partition { |e| e < pivot }

  qsort(left) + [pivot] + qsort(right)
end

def merge_sort(array)
  return array if array.length <= 1

  mid = array.length / 2
  left, right = array[0...mid], array[mid...array.length]

  merge(merge_sort(left), merge_sort(right))
end
