// Copyright (c) 2005-2023 Code Synthesis.
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis gives permission
// to link this program with the Xerces-C++ library (or with modified
// versions of Xerces-C++ that use the same license as Xerces-C++), and
// distribute linked combinations including the two. You must obey the GNU
// General Public License version 2 in all respects for all of the code
// used other than Xerces-C++. If you modify this copy of the program, you
// may extend this exception to your version of the program, but you are
// not obligated to do so. If you do not wish to do so, delete this
// exception statement from your version.
//
// Furthermore, Code Synthesis makes a special exception for the Free/Libre
// and Open Source Software (FLOSS) which is described in the accompanying
// FLOSSE file.
//

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/pre.hxx>

#include "calculatetable.hxx"

#include "tableType.hxx"

namespace streit
{
  // calculatetable
  //

  const calculatetable::table_sequence& calculatetable::
  table () const
  {
    return this->table_;
  }

  calculatetable::table_sequence& calculatetable::
  table ()
  {
    return this->table_;
  }

  void calculatetable::
  table (const table_sequence& s)
  {
    this->table_ = s;
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace streit
{
  // calculatetable
  //

  calculatetable::
  calculatetable ()
  : ::xml_schema::type (),
    table_ (this)
  {
  }

  calculatetable::
  calculatetable (const calculatetable& x,
                  ::xml_schema::flags f,
                  ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    table_ (x.table_, f, this)
  {
  }

  calculatetable::
  calculatetable (const ::xercesc::DOMElement& e,
                  ::xml_schema::flags f,
                  ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    table_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
      this->parse (p, f);
    }
  }

  void calculatetable::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // table
      //
      if (n.name () == "table" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< table_type > r (
          table_traits::create (i, f, this));

        this->table_.push_back (::std::move (r));
        continue;
      }

      break;
    }
  }

  calculatetable* calculatetable::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class calculatetable (*this, f, c);
  }

  calculatetable& calculatetable::
  operator= (const calculatetable& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->table_ = x.table_;
    }

    return *this;
  }

  calculatetable::
  ~calculatetable ()
  {
  }
}

#include <ostream>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream& o, const calculatetable& i)
  {
    for (calculatetable::table_const_iterator
         b (i.table ().begin ()), e (i.table ().end ());
         b != e; ++b)
    {
      o << ::std::endl << "table: " << *b;
    }

    return o;
  }
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

namespace streit
{
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

