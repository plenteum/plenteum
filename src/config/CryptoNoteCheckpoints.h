// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
//
// This file is part of Bytecoin.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Bytecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Bytecoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstddef>
#include <initializer_list>

namespace CryptoNote {
	struct CheckpointData {
		uint32_t index;
		const char* blockId;
	};

	const std::initializer_list<CheckpointData> CHECKPOINTS = {
	  {        0, "4755c750a1ed8535ba1789570899720f3cd010ccf7ab70a1a2d2d53f298eafd5"  },
	  {     1000, "7b5ed4e68acdf47e14bedffb4e35c734d909d9aace011e4cf52a68cd899558b2"  },
	  {     2000, "fd43c705668c66fc7bb7c000fc4512dbfd33abba4a8881f85dba6b3bcd0b50e2"  },
	  {     3000, "54b761d3ab816d6be1a768238aae9d4709871a893cc6da4d3a129b7af9a834cd"  },
	  {     4000, "6850385fc9bec6059c293e7056ae3c6434faf9d41a527141c981aacaf279097f"  },
	  {     5000, "d96fe66b8bb616aad90b009ae2f48d512a5217ccd289e4cc7a9305ed53a55359"  },
	  {     6000, "0fbd26172a1c1244d8afa93a25846c678e98e1d0ca1876b9f16dff74fbdd8238"  },
	  {     7000, "3403641299854d0d26b2d9610017db9904eacafc616656f65995c1e8571e8d20"  },
	  {     8000, "728fec3c8886a0fda848d325a0e195efbf48df250dea53ab8e86e7f6a2dcd1a9"  },
	  {     9000, "f0f7635680a534717986a0d1b9f5d223f69ee70cb53810b77771967e5db37d19"  },
	  {    10000, "787a85e48e6bc159cefd39ca0860ee711a7b7e697c918bcdc7c2764b0ba9a713"  },
	  {	   11000, "3a73cbd2a709c32a2f23567bd580c0cac407c124fe386a2de831ba2c5361c939"  },
	  {    12000, "c201f754a63390346fe05847bf62f17b4e2c655cfa0ceace92caa03b582ca03e"  },
	  {    13000, "60cf6a7e29374f4e9749d4513d9cd8b65edfa50e00d3d4d9d614f284804c50a7"  },
	  {    14000, "3cd01a4c32e48d6f037afa60a84527c023952df538db817719fc4e37431a66d1"  },
	  {    15000, "5737f0448ac0088fe7182b5ff339f405b3c418a56f52346f4c8cd41935fabd64"  },
	  {    20000, "5652668811f88cb9f5fff8031603760eacd15bad3ea85e3e08356f6e29f4a38b"  },
	  {    25000, "0bbc2086800ad08f5a2a83b775bebcbaccf12ffcc3685764e6cd83a73a5b34c4"  },
	  {    30000, "b7ac6cbad0b3c16cf1ed289f9ddd6ead1eae4a83e34cb931663f76ea7f254884"  },
	  {    35000, "4c840fd466b1e5a4cb483401a1bcaf249be0c18db86893cf5c2a69fef8aa1bd4"  },
	  {    40000, "75d853e29d25c477161aa1df310a74fa12fe2c06ca6c5dcd3bc89024dee34e91"  },
	  {    45000, "0cd2478c82bb4f853b9cf009e72d3df8c073c7068f23976c1cc9a06dcd7a306b"  },
	  {    50000, "36bb2c0b33b21776b79989076f84d18b819f31cc1849c6f858d0803c69c588f7"  },
	  
	  
	};
}
