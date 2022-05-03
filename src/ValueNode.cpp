#include <stdio.h>
#include "ValueNode.h"

/*        CONSTRUCT FUNCTION        */

/*      CONSTRUCT FUNCTION END      */

/*         PRINT FUNCTION         */

void IntegerNode::PrintContentInLevel(int level) const {
	printf("[int] %d\n", num);
}

void FloatNode::PrintContentInLevel(int level) const {
	printf("[float] %f\n", num);
}

/*        PRINT FUNCTION END        */