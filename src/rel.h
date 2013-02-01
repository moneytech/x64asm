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

#ifndef X64ASM_SRC_REL_H
#define X64ASM_SRC_REL_H

#include "src/op_type.h"
#include "src/operand.h"

namespace x64asm {

/** A relative address. */
class Rel : public AtomicOperand {
	public:
		inline Rel(uint64_t val) : AtomicOperand{val} { }
		virtual ~Rel() = 0;
		virtual void write_att(std::ostream& os) const;
		virtual void write_intel(std::ostream& os) const;
	private:
		virtual OpType type() const;
};

/** A relative address in the range from 128 bytes before the end of the 
	  instruction to 127 bytes after the end of the instruction.
*/
class Rel8 : public Rel {
	public:
		inline Rel8(int8_t val) : Rel{(uint64_t)val} { }
		virtual bool check() const;
	private:
		virtual OpType type() const;
};

/** A relative address within the same code segment as the instruction 
	  assembled. The rel32 symbol applies to instructions with an 
		operand-size attribute of 32 bits.
*/
class Rel32 : public Rel {
	public:
		inline Rel32(int64_t val) : Rel{(uint64_t)val} { }
		virtual bool check() const;
	private:
		virtual OpType type() const;
};

} // namespace x64asm

#endif