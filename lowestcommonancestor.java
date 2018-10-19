/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        TreeNode left=null;
        TreeNode right=null;
        
        if ((root.val == p.val) || (root.val == q.val) ){
            return root;
        }
        if (root.left != null){
            left = lowestCommonAncestor(root.left,p,q);
            
    }
        if (root.right != null){
            right = lowestCommonAncestor(root.right,p,q);
          
        }
        
        if ((left == null) && (right == null))
            return null;
        if(left!=null && right!=null)
            return root;
        if(left != null)
            return left;
        return right;
        
        
    }

    public static void main(String[] args){
        Solution.
    }
}