import itertools

class TreeNode(object):
    def __init__(self,x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root is None:
            return True
        else:
            gen_right = self.rightTravesal(root.right)
            gen_left = self.leftTravesal(root.left)
            for a,b in itertools.izip_longest(gen_right,gen_left):
                if a != b:
                    return False
            return True
    
    def rightTravesal(self,root):
        if root is not None:
            yield root.val
            for v in self.rightTravesal(root.right):
                yield v
            for v in self.rightTravesal(root.left):
                yield v
        else:
            yield 'null'
    
    def leftTravesal(self,root):
        if root is not None:
            yield root.val
            for v in self.leftTravesal(root.left):
                yield v
            for v in self.leftTravesal(root.right):
                yield v
        else:
            yield 'null'
