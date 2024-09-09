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

#include "diver.hxx"

#include "personType.hxx"

#include "buddy.hxx"

namespace streit
{
  // diver
  //

  const diver::owner_type& diver::
  owner () const
  {
    return this->owner_.get ();
  }

  diver::owner_type& diver::
  owner ()
  {
    return this->owner_.get ();
  }

  void diver::
  owner (const owner_type& x)
  {
    this->owner_.set (x);
  }

  void diver::
  owner (::std::unique_ptr< owner_type > x)
  {
    this->owner_.set (std::move (x));
  }

  const diver::buddy_sequence& diver::
  buddy () const
  {
    return this->buddy_;
  }

  diver::buddy_sequence& diver::
  buddy ()
  {
    return this->buddy_;
  }

  void diver::
  buddy (const buddy_sequence& s)
  {
    this->buddy_ = s;
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace streit
{
  // diver
  //

  diver::
  diver (const owner_type& owner)
  : ::xml_schema::type (),
    owner_ (owner, this),
    buddy_ (this)
  {
  }

  diver::
  diver (::std::unique_ptr< owner_type > owner)
  : ::xml_schema::type (),
    owner_ (std::move (owner), this),
    buddy_ (this)
  {
  }

  diver::
  diver (const diver& x,
         ::xml_schema::flags f,
         ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    owner_ (x.owner_, f, this),
    buddy_ (x.buddy_, f, this)
  {
  }

  diver::
  diver (const ::xercesc::DOMElement& e,
         ::xml_schema::flags f,
         ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    owner_ (this),
    buddy_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
      this->parse (p, f);
    }
  }

  void diver::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // owner
      //
      if (n.name () == "owner" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< owner_type > r (
          owner_traits::create (i, f, this));

        if (!owner_.present ())
        {
          this->owner_.set (::std::move (r));
          continue;
        }
      }

      // buddy
      //
      if (n.name () == "buddy" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< buddy_type > r (
          buddy_traits::create (i, f, this));

        this->buddy_.push_back (::std::move (r));
        continue;
      }

      break;
    }

    if (!owner_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "owner",
        "http://www.streit.cc/uddf/3.2/");
    }
  }

  diver* diver::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class diver (*this, f, c);
  }

  diver& diver::
  operator= (const diver& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->owner_ = x.owner_;
      this->buddy_ = x.buddy_;
    }

    return *this;
  }

  diver::
  ~diver ()
  {
  }
}

#include <ostream>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream& o, const diver& i)
  {
    o << ::std::endl << "owner: " << i.owner ();
    for (diver::buddy_const_iterator
         b (i.buddy ().begin ()), e (i.buddy ().end ());
         b != e; ++b)
    {
      o << ::std::endl << "buddy: " << *b;
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

