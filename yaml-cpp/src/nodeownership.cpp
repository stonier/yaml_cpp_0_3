#include "nodeownership.h"
#include "yaml-cpp-0.3/node.h"

namespace YAML_0_3
{
	NodeOwnership::NodeOwnership(NodeOwnership *pOwner): m_pOwner(pOwner)
	{
		if(!m_pOwner)
			m_pOwner = this;
	}
	
	NodeOwnership::~NodeOwnership()
	{
	}

	Node& NodeOwnership::_Create()
	{
		m_nodes.push_back(std::auto_ptr<Node>(new Node));
		return m_nodes.back();
	}

	void NodeOwnership::_MarkAsAliased(const Node& node)
	{
		m_aliasedNodes.insert(&node);
	}

	bool NodeOwnership::_IsAliased(const Node& node) const
	{
		return m_aliasedNodes.count(&node) > 0;
	}
}
