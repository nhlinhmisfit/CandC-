
typedef	struct _set{
	char	*key;
	void	*pValue;
}SET;

typedef	struct _single_node{
	void	*pData;
	struct _node	*ptr;
}SLLIST;

typedef	struct _double_node{
	void	*pData;
	struct _node	*left;
	struct _node	*right;
}DLLIST;
