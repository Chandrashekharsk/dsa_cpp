def binarySearch(nums, tar):
    nums.sort()
    st, end = 0, len(nums) - 1

    while st <= end:
        mid = st + (end - st) // 2

        if nums[mid] < tar:
            st = mid + 1
        elif nums[mid] > tar:
            end = mid - 1
        else:
            print("target exists there")
            return

    print("target doesn't exists there")


# test
size = input("Enter size of list: ")
if not size.isdigit() or int(size) <= 0:
    raise TypeError("Please enter valid number for size")
size = int(size)

nums = []
print(f"Enter {size} elements:")


for i in range(size):
    elem = input(f"Enter {i+1} element: ")
    if not elem.isdigit():
        raise ValueError("Please enter only numeric elements.")
    nums.append(int(elem))

tar = input("Enter target key to search: ")
if not tar.isdigit():
    raise ValueError("Please enter a numeric target key.")
tar = int(tar)
binarySearch(nums, tar)
