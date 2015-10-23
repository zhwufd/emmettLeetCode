from Solution import *

def main():
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(2)
    root.left.right = TreeNode(3)
    root.right.right = TreeNode(3)
    s = Solution()
    print s.isSymmetric(root)

if __name__ == '__main__':
    main()
