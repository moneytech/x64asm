/*
Copyright 2103 eric schkufza

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef X64ASM_SRC_MODIFIER_H
#define X64ASM_SRC_MODIFIER_H

#include <iostream>

#include "src/op_type.h"
#include "src/operand.h"

namespace x64asm {

/** A modifier. */
class Modifier : public AtomicOperand {
	public:
		inline Modifier(uint64_t val) : AtomicOperand{val} { }
		virtual ~Modifier() = 0;
		virtual void write_att(std::ostream& os) const;
		virtual void write_intel(std::ostream& os) const;
	private:
		virtual OpType type() const;
};

/** The 32-bit memory address override prefix: 0x66. */
class Pref66 : public Modifier {
	friend class Constants;
	public:
		virtual bool check() const;
	private:
		inline Pref66() : Modifier{0} { }
		virtual OpType type() const;	
};

/** The REX.w prefix: 0x48. */
class PrefRexW : public Modifier {
	friend class Constants;
	public:
		virtual bool check() const;
	private:
		inline PrefRexW() : Modifier{0} { }
		virtual OpType type() const;	
};

/** Far instruction variant. */
class Far : public Modifier {
	friend class Constants;
	public:
		virtual bool check() const;
	private:
		inline Far() : Modifier{0} { }
		virtual OpType type() const;	
};

} // namespace x64asm

#endif